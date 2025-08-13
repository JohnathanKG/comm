intergen_exe = executable('intergen',
    sources: ['ifc.h', 'ifc.js.h', 'ifc.lua.h', 'ig-arg.cpp', 'ig-class.cpp', 'ig-lexer.cpp', 'ig-method.cpp', 'ig.h', 'intergen.cpp', 'lua_utils.h', 'rl-method.cpp'],
    include_directories: [anteworld_inc, comm_inc],
    link_with: [comm_lib],
)

mtg_path = meson.current_source_dir() / 'metagen'
