import           Data.Char
import           Data.List
import           System.IO

type Program = String

data Command = Increment | Decrement | MoveLeft | MoveRight | Output | Input | LeftBracket | RightBracket | EOF deriving (Show, Read)

data Tape a = Tape [a] a [a] deriving (Show, Read)

parse :: Program -> Tape Command
parse program = Tape [EOF] (head commands) ((++ [EOF]) . tail $ commands) where
    commands = map translator program
    translator x = case x of
        '+'       -> Increment
        '-'       -> Decrement
        '<'       -> MoveLeft
        '>'       -> MoveRight
        '.'       -> Output
        ','       -> Input
        '['       -> LeftBracket
        ']'       -> RightBracket
        otherwise -> error "Invalid token"

emptyTape :: Tape Int
emptyTape = Tape zeros 0 zeros
  -- where zeros = take 10 $ repeat 0
  where zeros = repeat 0

moveLeft  :: Tape a -> Tape a
moveLeft  (Tape []     cur r) = error "Left end reached"
moveLeft  (Tape (l:ls) cur r) = Tape ls l (cur:r)

moveRight :: Tape a -> Tape a
moveRight (Tape l cur []    ) = error "Right end reached"
moveRight (Tape l cur (r:rs)) = Tape (cur:l) r rs

getCur :: Tape a -> a
getCur (Tape _ cur _) = cur

incCur :: (Num a) => Tape a -> Tape a
incCur (Tape l cur r) = Tape l (cur + 1) r

decCur :: (Num a) => Tape a -> Tape a
decCur (Tape l cur r) = Tape l (cur - 1) r

checkTape :: Tape Command -> Bool
checkTape = check 0 where
    check 0    (Tape _ _ []) = True
    check _    (Tape _ _ []) = False
    check (-1) (Tape _ _ _ ) = False
    check count tape@(Tape l c r) = case c of
        LeftBracket  -> check (count + 1) tape'
        RightBracket -> check (count - 1) tape'
        otherwise    -> check count tape'
        where tape' = moveRight tape

findNextPos :: Tape Command -> Tape Command
findNextPos tape@(Tape _ RightBracket _) = tape
findNextPos tape                         = moveRight tape

findPrevPos :: Tape Command -> Tape Command
findPrevPos = find 0 where
    find 1 tape@(Tape _ LeftBracket _) = tape
    find count tape@(Tape l c r) = case c of
        RightBracket -> find (count + 1) tape'
        LeftBracket  -> find (count - 1) tape'
        otherwise    -> find count tape'
        where tape' = moveLeft tape

execute :: Tape Command -> Tape Int -> IO ()
execute (Tape _ EOF []) tape = return ()
execute commands@(Tape _ cmd _) tape@(Tape l cur r) = case cmd of
    Increment -> execute commands' (incCur    tape)
    Decrement -> execute commands' (decCur    tape)
    MoveLeft  -> execute commands' (moveLeft  tape)
    MoveRight -> execute commands' (moveRight tape)
    Input     -> do
        p <- getChar
        execute commands' (Tape l (ord p) r) -- for ascii
        -- execute commands' (Tape l (read [p] :: Int) r) -- for numbers
    Output    -> do
        -- putStr $ show cur -- for numbers
        putChar (chr cur) -- for ascii
        hFlush stdout
        execute commands' tape
    LeftBracket  -> case cur of
        0         -> execute (findNextPos commands) tape
        otherwise -> execute commands' tape
    RightBracket -> case cur of
        0         -> execute commands' tape
        otherwise -> execute (findPrevPos commands) tape
    otherwise -> error "Not implemented"
    where commands' = moveRight commands

run :: Program -> IO ()
run program = case isValid of
    True  -> execute commands emptyTape
    -- True  -> putStrLn $ show $ getCur $ execute commands emptyTape
    False -> putStrLn "Program not Valid"
    where isValid  = checkTape commands
          commands = parse program

main = do
    input <- getLine
    run input
