DIR_MODINC +=	$(MOD) ../OneWire/common
ifeq '$(PORT)' 'unix'
DIR_MODINC += ../OneWire/lib/userial 
endif

