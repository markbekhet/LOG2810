#/usr/bin/bash

echo Hello!
git add .

echo enter the message of your commit
read message
git commit -m $message
git push
echo The script ran properly
