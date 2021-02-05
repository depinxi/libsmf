project "smf"
do
		kind "StaticLib"
		language "C"

		local version = "1.3.1"
		for k, v in pairs ({
			PACKAGE_VERSION = '"'..version..'"',
			VERSION = '"'..version..'"'
		}) do
			defines (k .. "=" .. v)
		end
		
		includedirs {
			"../../src",
			-- if use config.h
			-- "%{cfg.location}/%{cfg.shortname}/include"
		}
		files { 
			"../../src/smf.h",
			"../../src/smf.c",
			"../../src/smf_decode.c",
			"../../src/smf_load.c",
			"../../src/smf_tempo.c",
			"../../src/smf_private.h",
			"../../src/smf_save.c"
		}
		
		defines {
			"GLIB_COMPILATION"
		}
		
		sysincludedirs {
			"../../smfglib/include"
		}
		files {
			"../../smfglib/src/**.c"
		}
		
end
