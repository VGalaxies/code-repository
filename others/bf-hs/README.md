# bf-hs

https://git.nju.edu.cn/olahiuj/bf-hs/

A naive brainfuck interpreter using haskell

## 环境配置

https://www.cyberithub.com/how-to-install-haskell-platform-on-ubuntu-20-04-lts/

```
sudo apt-get install haskell-platform
```

交互模式

```
ghci
```

编译

```
ghc -o bf bf.hs
```


## RTFSC


`Program` 和 `emptyTape` 都是 `Tape` 类型构造器产生的类型



理解 `parse`

```haskell
parse :: Program -> Tape Command
parse program = Tape [EOF] (head commands) ((++ [EOF]) . tail $ commands) where ...
```

一些示例

```
*Main> parse "++--"
Tape [EOF] Increment [Increment,Decrement,Decrement,EOF]
*Main> (++ "1") . tail $ "123"
"231"
```



理解 `emptyTape`

```haskell
emptyTape :: Tape Int
emptyTape = Tape zeros 0 zeros
  -- where zeros = take 10 $ repeat 0
  where zeros = repeat 0
```

可以限制纸袋的长度

```
*Main> emptyTape
Tape [0,0,0,0,0,0,0,0,0,0] 0 [0,0,0,0,0,0,0,0,0,0]
```



`<>+-` 操作的实现都十分简单



`checkTape` 检查 `[]` 数量是否匹配

```haskell
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
```



寻找对应的 `[]` 十分精妙

```haskell
findNextPos :: Tape Command -> Tape Command
findNextPos tape@(Tape _ RightBracket _) = tape
findNextPos tape = moveRight tape

findPrevPos :: Tape Command -> Tape Command
findPrevPos = find 0 where
    find 1 tape@(Tape _ LeftBracket _) = tape
    find count tape@(Tape l c r) = case c of
        RightBracket -> find (count + 1) tape'
        LeftBracket  -> find (count - 1) tape'
        otherwise    -> find count tape'
        where tape' = moveLeft tape
```



后面就是 IO 的部分了

```haskell
execute :: Tape Command -> Tape Int -> IO ()
run :: Program -> IO ()
```
