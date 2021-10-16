project "nfd"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On" 
	targetdir ("bin/" .. "/%{prj.name}")
	objdir ("bin-obj/" .. "/%{prj.name}")

    files
    {
        "include/**.h",
        "include/**.hpp"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"
        files
        {
            "src/nfd_win.cpp"
        }

    filter "system:macosx"
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }
        files
        {
            "src/nfd_cocoa.m"
        }

    filter "system:linux"
        files
        {
            "src/nfd_gtk.cpp"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        symbols "Off"
        optimize "On"