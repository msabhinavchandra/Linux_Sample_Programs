# !/bin/bash

echo "1.View File"
echo "2.Check Disk"
echo "3.Exit"

read choice

case $choice in
1) cat server.c ;;
2) df -h ;;
3) exit ;;
*) echo "Invalid option" ;;
esac