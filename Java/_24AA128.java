// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// 24AA128
// This code is designed to work with the 24AA128_I2CMEM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class _24AA128
{
	public static void main(String args[]) throws Exception
	{
		// Create I2CBus
		I2CBus bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, 24AA128 I2C address is 0x50(80)
		I2CDevice device = bus.getDevice(0x50);

		// Select write register 0x0001
		byte[] data = new byte[3];
		// Address msb
		data[0] = 0x00;
		// Address lsb
		data[1] = 0x01;
		// data = 0x30(48)
		data[2] = 0x30;
		device.write(data, 0, 3);
		Thread.sleep(500);
		
		// Read 1 byte of data
		device.write(data, 0, 2);
		byte output = (byte)device.read();
		System.out.printf("Input Data : %d %n", output);
	}
}
