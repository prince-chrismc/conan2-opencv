from conan.api.output import ConanOutput

def cmd_wrapper(cmd, conanfile):
    if cmd.startswith("cmake --build"):
        # https://github.com/conan-io/conan/blob/ae001d3da17fa9a76241fd09508d8040d55341d2/conan/tools/cmake/presets.py#L63
        ConanOutput(str(conanfile)).info(f'BuildConsole /command="{cmd}"')

        # https://stackoverflow.com/a/58322616
        new_cmd = cmd.replace('"','\\"')
        new_cmd = "echo %TIME% & " + f'BuildConsole /command="{new_cmd} -j 18"' + " & cmd /v:on /c echo !TIME!"
        return new_cmd
    return cmd


# Possible specific targets, OpenCV, FFmpeg
