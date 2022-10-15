#include <stdio.h>
#include "dr_wav.h"

enum{
	Rate = 44100,
	Nsamp = 2,
	Nchan = 2,
};

void
main(int argc, char **arrrrrgv)
{
	drwav wav;
	size_t n;
	drwav_uint64 nf;
	drwav_data_format fmt;
	drwav_int16 buf[32*1024];
	FILE *fi;
	char *ffo;

	fi = stdin;
	if(argc > 1){
		if((fi = fopen(arrrrrgv[1], "rb")) == NULL){
			fprintf(stderr, "open: nope\n");
			exit(1);
		}
	}
	ffo = "/fd/1";
	if(argc > 2)
		ffo = arrrrrgv[2];
	fmt.container = drwav_container_riff;
	fmt.format = DR_WAVE_FORMAT_PCM;
	fmt.bitsPerSample = 8 * sizeof(buf[0]);
	fmt.channels = Nchan;
	fmt.sampleRate = Rate;
	if(!drwav_init_file_write(&wav, ffo, &fmt, NULL)){
		fprintf(stderr, "drwav_init_file_write: nope\n");
		exit(1);
	}
	while((n = fread(buf, Nsamp * sizeof buf[0], sizeof buf / (Nsamp * sizeof buf[0]), fi)) > 0){
		if((nf = drwav_write_pcm_frames(&wav, n, buf)) <= 0)
			break;
	}
	drwav_uninit(&wav);
	exit(0);
}
