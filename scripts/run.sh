make
chmod 755 build/connector
echo "Hello, World!\nMy Friend" | build/connector --single false --thread 4 2>&1
