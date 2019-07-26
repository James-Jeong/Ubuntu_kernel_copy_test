#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_SIZE 4096

// cp src dest
int main(int argc, char* argv[]){
	if(argc != 3){ printf("Usage : %s <source file> <destination file>\n", argv[0]); exit(0); }
	int fd_src, fd_dest;

	fd_src = open(argv[1], O_RDONLY);
	if(fd_src == -1){ printf("Failed to open %s\n", argv[1]); }
	else{
		fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(fd_dest == -1){ printf("Failed to create %s\n", argv[2]); return -1; }
		else{
			int fd_read = 0, fd_write;
			char* buf = malloc(FILE_SIZE); // 4KB Buffer

			if(buf == NULL) { perror("Failed to make buffer!!"); exit(0); }

			while(fd_read = read(fd_src, buf, FILE_SIZE)){
				if(fd_write = write(fd_dest, buf, fd_read)) continue;
				else{
					printf("Failed to write data in %s\n", argv[2]);
					break;
				}
			}
			close(fd_dest);
			free(buf);
		}
		close(fd_src);
	}
}
