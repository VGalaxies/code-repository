# 贪吃蛇

https://www.zhihu.com/question/360814879/answer/1013986215


## 安装 ncurses 库

```
$ sudo apt-get install libncurses5-dev
```

## 链接依赖

下述内容摘自 StackOverflow

> You make a very common beginners mistake... Putting the libraries you link with in the wrong place on the command line when you build.
>
> Dependencies are reversed on the command line, so something that depends on something else should actually be put *before* what it depends on on the command line.
>
> In your example, you have a source file `main.cpp` that depends on some set of libraries, then the source file should be before the libraries it depend on:
>
> ```ruby
> $ g++ -o main main.cpp -lssl -lcrypto
> ```
>
> To be safe, always put libraries *last*, after any source or object files listed on the command line.

所以 Makefile 如下：

```makefile
.PHONY: run clean

run: snake.c
	gcc snake.c -lncurses
	./a.out

clean:
	rm -f *.out
```

