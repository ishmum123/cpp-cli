make
chmod 755 build/cli
echo "Hello, World!\nMy Friend" | build/cli --single false 2>&1
