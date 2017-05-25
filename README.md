# CIS004B HashTable

**Proposal**: Let's call ourselves the JJJ Collective INC.

**Note**: Jorge's code is in the aptly-named `jorge` branch. It could use some formatting and more testing but that will definitely get the job done as is if we want to roll with that.

### `useless instructions --verbose`
#### Project Layout:
Our project structure is a simplified version of the [GNU C++ standard project structure](https://gcc.gnu.org/codingconventions.html). It looks like this:

- Makefile
- /include
  * header files (*.hpp)
- /src
  * implementation files (*.cpp) eg. tests
- /tests
    - we dont have this directory but I think it's a good candidate for where our tests should go if we ever work together on a project that actually matters.


The Makefile and project structure we've been using in this assignment and our last few assignments come from this [blogpost](http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/) by Hilton Lipschitz, a "CTO at an up and coming Hedge Fund." He's got a lot of good posts on C++ and Apple stuff if you want to check it out at [hiltmon.com](https://hiltmon.com).

If you want to learn way too much about how Makefiles work the documentation lives at [gnu.org](https://www.gnu.org/software/make/manual/make.html).

### Building the Project

    $ make clean
    $ make
    $ bin/EXECUTABLE

I try to name our executables the same as our project name. So usually `EXECUTABLE` will be `PROJECT_NAME`. If it's not for some reason you can look in the Makefile and go ahead and run that or change it to whatever our project is called.

Because we are compiling a single program, if you have autocomplete installed (Cloud9 terminal does) then you can just type `bin/`, hit `TAB` , then press `ENTER`. Whatever that file path resolves to will be the executable program.

