-- Workspace
workspace "Sandbox"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

-- output directory name
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

externalproject "GodHunter"
    location "../Engine/GodHunter"
    kind "SharedLib"
    language "C++"


-- Project Sandbox (Game)
project "Sandbox"
    -- Project informations
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    -- Project Compile directory
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    -- Included files
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    -- Connect with vendors
    includedirs
    {
        "../Engine/GodHunter/src"
    }

    libdirs
    {
        
    }

    links
    {
        "GodHunter"
    }
    
    -- Filter if System is Windows
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
    
        defines
        {
            "GH_PLATFORM_WINDOWS"
        }
    
    -- Filter for configurations
    filter "configurations:Debug"
        defines "GH_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GH_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GH_DIST"
        optimize "On"

