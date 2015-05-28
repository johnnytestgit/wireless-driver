obj-$(CONFIG_WILC1000) += wilc1000.o
obj-$(CONFIG_WILC1000_PREALLOCATE_DURING_SYSTEM_BOOT) += wilc_exported_buf.o


ccflags-$(CONFIG_WILC1000_SDIO) += -DWILC_SDIO -DCOMPLEMENT_BOOT -DWILC_OPTIMIZE_SLEEP_INT
 
ccflags-$(CONFIG_WILC1000_HW_OOB_INTR) += -DWILC_SDIO_IRQ_GPIO
ccflags-$(CONFIG_WILC1000_SPI) += -DWILC_SPI

ccflags-y += -DSTA_FIRMWARE
ccflags-y += -DSTA_FIRMWARE_1002=\"atmel/wilc1000a_fw_v12.2.bin\" \
		-DSTA_FIRMWARE_1003=\"atmel/wilc1000b_fw_v12.2.bin\"

ccflags-y += -I$(src)/ -DEXPORT_SYMTAB  -D__CHECK_ENDIAN__ -DWILC_ASIC_A0 \
		-DPLL_WORKAROUND -DCONNECT_DIRECT  -DAGING_ALG \
		-DWILC_PARSE_SCAN_IN_HOST -DDISABLE_PWRSAVE_AND_SCAN_DURING_IP \
		-DWILC_PLATFORM=WILC_LINUXKERNEL -Wno-unused-function -DUSE_WIRELESS \
		-DSTATIC_MACADDRESS -DWILC_DEBUGFS
ccflags-y += -DTCP_ACK_FILTER
ccflags-y += -DTCP_ENHANCEMENTS 

ccflags-y += -DHAS_SUSPEND_RESUME

ccflags-$(CONFIG_WILC1000_PREALLOCATE_DURING_SYSTEM_BOOT) += -DMEMORY_STATIC \
								-DWILC_PREALLOC_AT_BOOT

ccflags-$(CONFIG_WILC1000_PREALLOCATE_AT_LOADING_DRIVER) += -DMEMORY_STATIC \
								-DWILC_PREALLOC_AT_INSMOD

ccflags-$(CONFIG_WILC1000_DYNAMICALLY_ALLOCATE_MEMROY) += -DWILC_NORMAL_ALLOC


wilc1000-objs := wilc_wfi_netdevice.o wilc_wfi_cfgoperations.o linux_wlan.o linux_mon.o \
			wilc_memory.o wilc_msgqueue.o wilc_semaphore.o wilc_sleep.o wilc_strutils.o \
			wilc_thread.o wilc_time.o wilc_timer.o coreconfigurator.o host_interface.o \
			fifo_buffer.o wilc_sdio.o wilc_spi.o wilc_wlan_cfg.o wilc_debugfs.o

wilc1000-$(CONFIG_WILC1000_SDIO) += linux_wlan_sdio.o
wilc1000-$(CONFIG_WILC1000_SPI) += linux_wlan_spi.o

WILC1000_SRC_VERSION = 12.2
PATCHLEVEL = 1
WILC1000_FW_VERSION = 0

ccflags-y += -D__DRIVER_VERSION__=\"$(WILC1000_SRC_VERSION).$(PATCHLEVEL)\"
