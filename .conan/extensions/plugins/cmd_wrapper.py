from conan.api.output import ConanOutput

def cmd_wrapper(cmd, conanfile):
    if cmd.startswith("cmake --build"):
        # https://github.com/conan-io/conan/blob/ae001d3da17fa9a76241fd09508d8040d55341d2/conan/tools/cmake/presets.py#L63
        ConanOutput(str(conanfile)).info(f'BuildConsole /command="{cmd}"')
        # new_cmd = cmd[6:].replace("\"","")
        # print(new_cmd)
        new_cmd = "', '".join(cmd.split(" "))
        print(str(conanfile), new_cmd)
        new_cmd = "PowerShell -NoProfile -ExecutionPolicy Bypass -Command Measure-Command {Start-Process cmake -ArgumentList  @('" + new_cmd + "') -wait | Out-Default}"
        print(new_cmd)
        return new_cmd
    return cmd


# Possible specific targets, OpenCV, FFmpeg
