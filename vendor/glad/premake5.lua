project "glad"
    kind "StaticLib"
    language "C"
    staticruntime "On" 
	targetdir ("bin/" .. "/%{prj.name}")
	objdir ("bin-obj/" .. "/%{prj.name}")

    files
    {
        "include/**.h",
        "src/**.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:macosx"
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["UseModernBuildSystem"] = "NO"
        }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        symbols "Off"
        optimize "On"