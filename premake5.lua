workspace "AndromedaV2"
	architecture "x64"

	configurations
	{
		"Debug",
		"DebugEditor",
		"DebugOptimized",
		"DebugOptimizedEditor",
		"Release"
	}
	
	platforms
	{
		"Win64",
		"MacOS",
		"Linux",
		"XBSX",
		"PS5"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AndromedaV2"
	location "AndromedaV2"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Bin-Intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp",
		"%{prj.name}/Source/**.hpp"
	}

	includedirs
	{
		"Dependencies/GLEW",
		"Dependencies/GLFW",
		"%{prj.name}/Source"
	}
	
	libdirs
	{
		"Dependencies/GLEW",
		"Dependencies/GLFW",
	}
	
	links {
		"glew32s.lib",
		"glfw3.lib",
		"opengl32.lib",
	}
	
	cppdialect "C++20"
	staticruntime "off"
	systemversion "latest"
	
	defines
	{
		"GLEW_BUILD",
		"GLFW_INCLUDE_NONE"
	}
	
	filter "system:not windows"
		
		defines
		{
			"AD_COMPILE_HOST_PLATFORM_OTHER"
		}

	filter "system:windows"

		defines
		{
			"AD_COMPILE_HOST_PLATFORM_WINDOWS"
		}
		
	filter {}

	filter "configurations:Debug"
		defines "AD_DEBUG"
		symbols "On"
		optimize "Off"
	
	filter "configurations:DebugEditor"
		defines "AD_DEBUG"
		defines "AD_EDITOR"
		symbols "On"
		optimize "Off"
		
	filter "configurations:DebugOptimized"
		defines "AD_DEBUG"
		optimize "On"
		symbols "On"
		
	filter "configurations:DebugOptimizedEditor"
		defines "AD_DEBUG"
		defines "AD_EDITOR"
		symbols "On"
		optimize "On"

	filter "configurations:Release"
		defines "AD_RELEASE"
		optimize "On"
		symbols "Off"
		
	filter "platforms:Win64"
		defines "AD_WIN64"
		
	filter "platforms:MacOS"
		defines "AD_MACOS"
	
	filter "platforms:Linux"
		defines "AD_LINUX"
		
	filter "platforms:XBSX"
		defines "AD_XBSX"
		
	filter "platforms:PS5"
		defines "AD_PS5"

	filter {}