#ifndef _I2C_MASTER_H_
#define _I2C_MASTER_H_

void i2c_master_init(void);
int32_t i2c_master_write(uint8_t *data, uint8_t slave_addr, int32_t n_bytes);
int32_t i2c_master_read(uint8_t *data, uint8_t slave_addr, int32_t n_bytes);


#endif