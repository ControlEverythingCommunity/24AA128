# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# 24AA128
# This code is designed to work with the 24AA128_I2CMEM I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/products

from OmegaExpansion import onionI2C
import time

# Get I2C bus
i2c = onionI2C.OnionI2C()

# 24AA128 address, 0x50(80)
# Select write address
#		0x0001(01)
# Select write data
#		0x30(48)
data = [0x01 , 0x30]
i2c.writeBytes(0x50, 0x00, data)

time.sleep(0.5)

# 24AA128 address, 0x50(80)
# Select read address
data = [0x01]
i2c.writeBytes(0x50, 0x00, data)

time.sleep(0.5)

# 24AA128 address, 0x50(80)
# Read data back
data = i2c.readBytes(0x50, 0x00, 1)

# Output data to screen
print "Input Data : ",data[0]
