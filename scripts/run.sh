make
chmod 755 build/cli
echo "Hello, World!" | build/cli --single false 2>&1
