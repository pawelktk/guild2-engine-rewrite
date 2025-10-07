#pragma once
#include <fstream>
#include <string>
#include <chrono>
#include <utility> // std::move


#define USE_NATIVE_BINDINGS //TODO move it somewhere more appropriate

namespace Profiling {


    inline constexpr size_t FLUSH_THRESHOLD = 10 * 1024 * 1024; // 10 MB
    inline std::string log_buffer;
    inline bool header_written = false;

    inline const char* GetLogFilename() {
        #ifdef USE_NATIVE_BINDINGS
            return "G2ER_NATIVE_Profiling.log";
        #else
            return "G2ER_Profiling.log";
        #endif
    }

    inline void Flush() {
        if (log_buffer.empty()) {
            return;
        }
        std::string buffer_to_write = std::move(log_buffer);
        log_buffer.reserve(FLUSH_THRESHOLD);
        std::ofstream log_file(GetLogFilename(), std::ios::out | std::ios::app);
        if (log_file.is_open()) {
            if (!header_written) {
                log_file.close();
                log_file.open(GetLogFilename(), std::ios::out | std::ios::trunc);
                log_file << "FunctionName,Duration_ns\n";
                header_written = true;
            }
            log_file << buffer_to_write;
        }
    }

    inline void Init() {
        log_buffer.reserve(FLUSH_THRESHOLD);
        header_written = false;
    }

    inline void Shutdown() {
        Flush();
    }

    inline void LogCall(const char* func_name, long long duration_us) {
        log_buffer += func_name;
        log_buffer += ',';
        log_buffer += std::to_string(duration_us);
        log_buffer += '\n';
        if (log_buffer.size() > FLUSH_THRESHOLD) {
            Flush();
        }
    }

}