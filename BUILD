"This is a Bazel build file for the 'comm' static library."

load("@rules_cc//cc:cc_library.bzl", "cc_library")

cc_library(
    name = "comm_static",
    srcs =
        glob(
            include = [
                "*.h",
                "*.cpp",
                "**/*.c",
                "**/*.h",
                "**/*.cpp",
                "**/*.hpp",
            ],
            exclude = [
                "**/comm_test*/**",
                "**/tests/**",
                "**/*.jsc.*",
                "**/coder/lz4/**",
            ],
        ),
    copts = [
        "/MP",
        "/Od",
    ],
    deps = [
        "//glm:glm",
    ],
    visibility = ["//visibility:public"],
)
