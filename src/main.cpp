#include <fmt/format.h>
#include <spdlog/spdlog.h>

int main() {
    fmt::print(FMT_STRING("Hello World! - from fmt\n"));
    spdlog::log(spdlog::level::info, "Hello World! - from spdlog\n");
    int val[11];
    val[10] = 100;
    fmt::print("Olha o valor: {}", val[10]);
    return 1;
}
