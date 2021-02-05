newoption {
	trigger = "location",
	description = "Path of generated build scripts",
	value = "path",
	default = "build/premake" 
}

newaction {
	trigger = "config",
	description = "Create config.h",
	onWorkspace = function(wks)
		for cfg in premake.workspace.eachconfig (wks) 
		do
			local filename = path.join (cfg.location, cfg.shortname, "include/config.h")
			local ctx = {
				["cfg"] = cfg,
				["filename"] = filename 
			}
			premake.generate (ctx, nil, function (ctx)
				premake.w ("/** Generated by premake */")
				local version = "1.3.1"
				for k, v in pairs ({
					PACKAGE_VERSION = '"'..version..'"',
					VERSION = '"'..version..'"'
				}) do
					premake.w ("#define " .. k .. " " .. v)
				end
			end)
		end
	end 
}

workspace "smf"
do
	configurations {"Debug", "Release" }
	location (_OPTIONS["location"])
	include "scripts/premake/libsmf.lua"
end