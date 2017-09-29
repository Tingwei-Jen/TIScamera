/*
 * v4ldevice.h
 *
 *  Created on: Sep 19, 2017
 *      Author: tingwei
 */

#ifndef V4LDEVICE_H_
#define V4LDEVICE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include <linux/videodev2.h>

#define CLEAR(x) memset(&(x), 0, sizeof(x))

class v4ldevice {
public:
	v4ldevice();
	virtual ~v4ldevice();

	void open_device(char* devicename);
	void close_device(void);
	void init_device (int width, int height );
	void uninit_device (void);
	void start_capturing (void);
	void stop_capturing (void);
	unsigned char* snapFrame();

private:
    void init_userp (unsigned int buffer_size);
    void init_mmap (void);
	void init_read (unsigned int buffer_size);	
	int read_frame (void);
	void errno_exit (const char *s);
	int xioctl (int fh, int request, void *arg);

	enum io_method
	{
	    IO_METHOD_READ,
	    IO_METHOD_MMAP,
	    IO_METHOD_USERPTR,
	};
	struct buffer
	{
	    void   *start;
	    size_t  length;
	};

	struct v4l2_buffer buf;

	char            dev_name[1024];
	enum io_method   io = IO_METHOD_MMAP;
	int              fd = -1;
	struct buffer          *buffers;
	unsigned int     n_buffers;
	int              out_buf;
	int              force_format = 1;
	int              frame_count = 10;

};

#endif /* V4LDEVICE_H_ */

