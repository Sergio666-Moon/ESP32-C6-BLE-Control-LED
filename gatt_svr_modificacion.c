extern void controlar_led_rgb(uint8_t comando);

        rc = gatt_svr_chr_write(ctxt->om,
                                sizeof gatt_svr_sec_test_static_val,
                                sizeof gatt_svr_sec_test_static_val,
                                &gatt_svr_sec_test_static_val, NULL);

        controlar_led_rgb(gatt_svr_sec_test_static_val);

        return rc;
