workspace "GioBoyAdvance"
    startproject "GioBoyAdvance"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
tdir = "bin\\" .. outputdir .. "\\%{prj.name}"
odir = "bin-obj\\" .. outputdir .. "\\%{prj.name}"

-- External Dependencies
externals = {}
externals["sdl2"] = "vendor\\sdl2"
externals["spdlog"] = "vendor\\spdlog"

project "GioBoyAdvance"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir (tdir)
    objdir (odir)

    files
    {
        "include/**.h",
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "include/platform",
        "include/gba",
        "%{externals.sdl2}/include",
        "%{externals.spdlog}/include"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "GIO_PLATFORM_WINDOWS"
        }

        libdirs
        {
            "%{externals.sdl2}/lib"
        }

        links
        {
            "SDL2"
        }

        postbuildcommands
        { 
            "copy \"$(ProjectDir)%{externals.sdl2}\\lib\\sdl2.dll\" \"$(ProjectDir)$(OutputDir)%{tdir}\""
        }

    filter "system:macosx"
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }

        defines
        {
            "GIO_PLATFORM_MAC"
        }
        
        links
        {
            "SDL2.framework"
        }
    
    filter "system:linux"
        defines
        {
            "GIO_PLATFORM_LINUX"
        }

        links
        {
            "SDL2"
        }

    filter "configurations:Debug"
        symbols "On"
        defines
        {
            "GIO_CONFIG_DEBUG"
        }

    filter "configurations:Release"
        optimize "On"
        defines
        {
            "GIO_CONFIG_RELEASE"
        }
    