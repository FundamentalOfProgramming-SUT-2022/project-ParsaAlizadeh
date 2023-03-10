#include "openfile.h"
#include "setup.h"

typedef struct {
    char *path;
} openfile_t;

static void *make(void) {
    openfile_t *this = malloc(sizeof(openfile_t));
    this->path = NULL;
    return this;
}

static int set_opt(void *_this, int c, char *argv) {
    openfile_t *this = _this;
    switch (c) {
    SINGLE_OPTION_ARGV('f', path)
    default:
        return CMD_UNEXPECTED;
    }
    return CMD_SUCCESS;
}

static void run(void *_this, char *inp, char **out) {
    (void)inp;
    (void)out;
    openfile_t *this = _this;
    if (this->path == NULL || strcmp(this->path, BUFFER_PATH) == 0)
        return (void)cmdlogrequired(&openfile, 'f');
    if (ed == NULL) {
        ctx_set(CTX_PATH, this->path);
        return;
    }
    editor_run_end(NULL);
    if (editor_writectx() == -1)
        cmdlog(&openfile, "failed to save previous buffer, ignoring");
    ctx_set(CTX_PATH, this->path);
    if (editor_readctx() == -1) {
        cmdlog(&openfile, "failed to open file, will open an empty file: %s",
            strerror(errno));
        editor_setvc(vc_new1());
        editor_reset();
        ed->modified = 1;
    } else {
        editor_reset();
    }
    editor_run_init();
}

const command openfile = {
    .name       = "open",
    .optstring  = "f:",
    .usage      = "-f FILE",
    .make       = make,
    .set_opt    = set_opt,
    .run        = run,
    .free       = free
};
