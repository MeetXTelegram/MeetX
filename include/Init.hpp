#pragma once

#include <csignal>

#include <spdlog/spdlog.h>

#include <Args.hpp>
#include <Definitions.hpp>
#include <PSQLWrapper.hpp>

namespace init {
    inline void MeetXInit(ah::Args& argsHandler) {
        if (!argsHandler.getArg("dbname").has_value()) {
            spdlog::log(spdlog::level::critical, "Failed to init MeetX: the \"dbname\" argument is not provided");
            std::raise(SIGUSR1);
        }
        auto dbname = argsHandler.getArg("dbname").value().second;

        if (!argsHandler.getArg("password").has_value()) {
            spdlog::log(spdlog::level::critical, "Failed to init MeetX: the \"password\" argument is not provided");
            std::raise(SIGUSR1);
        }
        auto password = argsHandler.getArg("password").value().second;

        auto stdoutSink = createStdoutSink;
        auto fileSink = createFileSink("/home/username000101/SPDLOG_MEETX_TEST.txt");
        loggingUtils::createLogger("MAIN_LOGGER", stdoutSink, fileSink, spdlog::level::trace);
        loggingUtils::createLogger("ArgsHandler", stdoutSink, fileSink, spdlog::level::trace);
    }
}
