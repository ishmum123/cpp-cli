# Cpp Cli - Zigbee/BLE Connector

Connect to your Zigbe/BLE devices from the command line. 

An easy to use application where you can chose your protocol and pass messages to your Zigbee/BLE devices.

## Usage
```shell
connector --protocol zigbee --message "Hello, World!"
```

p.s. - This project uses modern C++ standards and libraries

# Build Steps

The following steps assume you are running Ubuntu 22.04 or above - 

* Install abseil library - `sudo apt install libabsl-dev`
* Clone the `rfl` library to your `/usr/local/include/` folder - `git clone https://github.com/getml/reflect-cpp /usr/local/include/`
* Use `make` to generate the `build/connector` file
* Use `scripts/run.sh` to run the connector with dummy arguments
* Use `scripts/test.sh` to run all tests
