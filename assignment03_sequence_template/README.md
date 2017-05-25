# Assignment 03 - Sequence/LinkedList/whatever the fuck template

Pg 350 Problem 02

## Testing on your local machine
1. Make sure you accepted the colloboration request so you have access to the
   git repository.
2. In your terminal, type `git clone https://github.com/jchaffin/cis004b_assignment04_double_ended_queue.git`
   in the directory where you want this project to be on your local filesystem.
   ie. ~/Developer/Projects
   Then `cd cis004b_assignment04_double_ended_queue/`

## Testing in Cloud9
1.  Open Terminal - `M-t` (alt key plus "t" key) in default mode OR `C-`` in sublime mode
2. Make sure you are in the directory workspace and on the branch "develop"
   The current git branch is the segment to the far right in parenthesis
     - If you are not on the develop branch enter the following command
       in the terminal: `git checkout develop && git pull`. If they
       are merge conflicts then try `git pull --force` or `git merge origin/develop --force`
3. Make your changes
4.  a. When you have made a significant number of modifications,
      track files, commit your changes, and push to remote using the
      following set of commands:
      ```bash
        git add .
        git commit -m "YOUR CHANGES"
        git push -u
      ```
    b. If you have made changes that implement a new feature but doesn't compile
       or has a bug, create a new branch and commit your changes there with the
       following:
       ```bash
        git branch features/your-feature
        git checkout features/your-feature
        git add .
        git commit -m "YOUR CHANGES"
        git push -u
       ```

    c. Continue working on this branch until the code is stable or too fucked up
       to continue. In the former case, merge your changes to the `develop` branch.
       In the latter, stash your changes and checkout the develop branch to continue
       where you left off. You can do this like so:
       ```bash
       git stash NAME
       git checkout develop
       git pull
      ```

    d. If at any time you forget to checkout a new branch or want to reset your
       working tree to the last commit, you can do so by typing
       ```bash
       git reset --hard
       git checkout <branch>
      ```
5. Earn this balloon. 🎈
6. If you are doing pomodoro, take your break.
7. Repeat.


## Resources
Please add any useful resources here:
- [ Markdown Cheatsheet ](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
- [ C++ Styleguide ](https://google.github.io/styleguide/cppguide.html)
- [Git Workflows](https://www.atlassian.com/git/tutorials/comparing-workflows)
- [C++ Templates](http://en.cppreference.com/w/cpp/language/templates)

### Collaborators
- [Jacob Chaffin](https://github.com/jchaffin/)
- [Jeevan Basnet](https://github.com/jeevan1133)
- [Jorge Tadeo](https://github.com/Getm0ney)