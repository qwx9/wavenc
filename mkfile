</$objtype/mkfile
BIN=/$objtype/bin/audio

TARG=\
	wavenc\
	#wavdec\

OFILES=\
	wavenc.$O\

HFILES=\
	dr_wav.h\

</sys/src/cmd/mkmany

CC=pcc
CFLAGS=-c -p -DDR_WAV_IMPLEMENTATION -DDR_WAV_NO_WCHAR
