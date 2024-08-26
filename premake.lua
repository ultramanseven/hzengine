workspace "HzEngine"
    architecture "x64"

    configurations{
        "Debug",
        "Release",
        "Dist",
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HzEngine"
    location "HzEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    targetdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h"
        "%{prj.name}/src/**.cpp"
    }

    include{
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticcruntime "On"
        systemversion "10.0.18362.0"

        defines{
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
 
    HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;_WINDLL;