# pipe
## This project will let discover in detail a UNIX mechanism.

Program will be executed as follows:

> ./pipex file1 cmd1 cmd2 file2
 
It must take 4 arguments:
 
• file1 and file2 are file names.
 
• cmd1 and cmd2 are shell commands with their parameters.
  
It must behave exactly the same as the shell command below:
>  $> < file1 cmd1 | cmd2 > file2

---

### ***And also...***

Handle multiple pipes:
> $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

Support « and » when the first parameter is "here_doc".
> $> ./pipex here_doc LIMITER cmd cmd1 file
  
 the program behaves like:
 >  cmd << LIMITER | cmd1 >> file
