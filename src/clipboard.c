#include "clipboard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE *clip = NULL;

FILE *clipboard_reset(void) {
    if (clip != NULL)
        fclose(clip);
    clip = tmpfile();
    return clip;
}

FILE *clipboard_get(void) {
    if (clip == NULL)
        return clipboard_reset();
    rewind(clip);
    return clip;
}
