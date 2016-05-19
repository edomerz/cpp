/* Excerpt from pipe_select() in /usr/src/sys/kern/sys_pipe.c */switch (which) {
case FREAD:
  if ( (rpipe->pipe_state & PIPE_DIRECTW) ||
       (rpipe->pipe_buffer.cnt > 0) ||
       (rpipe->pipe_state & PIPE_EOF)) {
         return (1);
  }
  selrecord(p, &rpipe->pipe_sel);
  rpipe->pipe_state |= PIPE_SEL;
  break;
case FWRITE:
  if ((wpipe == NULL) ||
      (wpipe->pipe_state & PIPE_EOF) ||
      (((wpipe->pipe_state & PIPE_DIRECTW) == 0) &&
       (wpipe->pipe_buffer.size - wpipe->pipe_buffer.cnt) >= PIPE_BUF)) {
          return (1);
  }
  selrecord(p, &wpipe->pipe_sel);
  wpipe->pipe_state |= PIPE_SEL;
  break;
case 0:
  if ((rpipe->pipe_state & PIPE_EOF) ||
      (wpipe == NULL) ||
      (wpipe->pipe_state & PIPE_EOF)) {
         return (1);
  }
  selrecord(p, &rpipe->pipe_sel);
  rpipe->pipe_state |= PIPE_SEL;
  break;
}
