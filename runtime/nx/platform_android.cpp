#include "platform.h"
#include <android/log.h>
#include <unistd.h>
#include "../nx/nvn_pipeline_cache.h"

// Parche para forzar el guardado de la caché en pausa y eventos de ciclo de vida (GPU Mali)
void on_cmd(int cmd) {
    switch (cmd) {
        case APP_CMD_PAUSE:
        case APP_CMD_LOST_FOCUS:
        case APP_CMD_DESTROY:
            nx::nvn::pipeline_cache_flush();
            __android_log_print(ANDROID_LOG_INFO, "P4G_Mali", "Caché de pipeline guardada exitosamente en pausa.");
            break;
        default:
            break;
    }
}
