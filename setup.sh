#!/bin/zsh
echo -n 'mac or win or linux?[m/n/l]: '
read env_name
if [ "$env_name" = 'm' -o "$env_name" = 'l' ]; then
    cp -r .os_vscode/.mac_vscode ./
    mv -i .mac_vscode .vscode
    echo 'copy .mac_vscode as .vscode'
elif [ "$env_name" = 'n']; then
    cp -r .os_vscode/.win_vscode ./
    mv -i .win_vscode .vscode
    echo 'copy .win_vscode as .vscode'
fi

echo "install snippet convert tool [lib2snippet]..."
pip install git+https://github.com/kashee337/lib2snippet.git
