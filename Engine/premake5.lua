-- Workspace
workspace "GodHunter"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

-- output directory name
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Path to vendors
-- pathToSDL = "D:/GE_project/engine/GodHunter/GodHunter/vendor/SDL2/SDL2-2.26.1"

-- Project Godhunter Engine (Library)
project "GodHunter"
    -- Project informations
    location "GodHunter"
    kind "SharedLib"
    language "C++"

    -- Project Compile directory
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- Included files
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.c"
    }

    -- Connect with vendors
    includedirs
    {
        -- "%{prj.name}/vendor/SDL2/SDL2-2.26.1/include"
    }

    libdirs
    {
        -- "%{prj.name}/vendor/SDL2/SDL2-2.26.1/lib/x64"
    }

    links
    {
        -- (pathToSDL .. "/lib/x64/SDL2main"),
        -- (pathToSDL .. "/lib/x64/SDL2")
    }

    -- Filter if System is Windows
    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "GH_PLATFORM_WINDOWS",
            "GH_BUILD_SHAREDLIB"
        }

        postbuildcommands
        {
            -- ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/GamePrj"),
            -- ("{COPY} " .. pathToSDL .. "/lib/x64/SDL2.dll ../bin/" .. outputdir .. "/GamePrj")
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
