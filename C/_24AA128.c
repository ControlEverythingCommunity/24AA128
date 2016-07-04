// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// 24AA128
// This code is designed to work with the 24AA128_I2CMEM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, 24AA128 I2C address is 0x50(80)
	ioctl(file, I2C_SLAVE, 0x50);

	// Select write address(0x0001)
	// Write the data(0x30)
	char config[3] = {0};
	config[0] = 0x00;
	config[1] = 0x01;
	config[2] = 0x30;
	write(file, config, 3);
	sleep(1);

	// Read 1 byte of data from register(0x0001)
	// input data 
	write(file, config, 2);
	char data[1] = {0};
	if(read(file, data, 1) != 1)
	{
		printf("Error : Input/Output Error \n");
		exit(1);
	}
	else
	{
		// Output data to screen
		printf("Input Data : %x \n", data[0]);
	}
}
