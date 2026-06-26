project(
  'EccEdc',
  'c',
  'cpp',
  default_options : ['buildtype=release', 'cpp_std=c++11']
)

conf_data = configuration_data()

compiler = meson.get_compiler('cpp')
compiler_flags = []
linker_flags = []

dependencies = []

xp_compat = get_option('enable_xp_compat')

if host_machine.system() == 'windows'
  if xp_compat
    compiler_flags += ['-D_WIN32_WINNT=0x0501', '-DWINVER=0x0501', '-O2']
    linker_flags += ['-static', '-static-libgcc', '-static-libstdc++', '-Wl,--subsystem,console:5.01']
  else
    compiler_flags += ['-DWINVER=0x0A00', '-D_WIN32_WINNT=0x0A00']
  endif
  dependencies += compiler.find_library('shlwapi', required: true)
endif

src_files = files(
  # external
  'EccEdc/_external/ecm.cpp',
  'EccEdc/_external/ecm.h',
  # EccEdc
  'EccEdc/Enum.h',
  'EccEdc/EccEdc.cpp',

)

all_sources = [src_files]

os_type = target_machine.system()

if os_type == 'linux'
  all_sources += files(
  'EccEdc/_linux/defineForLinux.h',
  'EccEdc/_linux/defineForLinux.cpp',
  )
endif

if os_type == 'windows'
  all_sources += files(
  'EccEdc/FileUtils.cpp',
  'EccEdc/FileUtils.hpp',
  'EccEdc/StringUtils.cpp',
  'EccEdc/StringUtils.hpp',
  )
endif

inc = [include_directories('EccEdc/'), include_directories('EccEdc/_external')]

# Flags for MinGW / GCC / Clang
gcc_args = ['-Wall', '-Wextra', '-Wno-unknown-pragmas']

# Equivalent flags for MSVC (Visual Studio)
msvc_args = [
  '/W4',                        # High warning level (equivalent to -Wall + -Wextra)
  '/wd4068'                     # Disable warning C4068: unknown pragma (equivalent to -Wno-unknown-pragmas)
]

cpp_compiler = meson.get_compiler('cpp')
c_compiler = meson.get_compiler('c')

# Meson will test the list and pick only the arguments supported by the active compiler
supported_cpp_args = cpp_compiler.get_supported_arguments(gcc_args + msvc_args)
supported_c_args = c_compiler.get_supported_arguments(gcc_args + msvc_args)

executable(
  meson.project_name(),
  sources: [
  all_sources
  ],
  dependencies: dependencies,
  include_directories: inc,
  cpp_args: supported_cpp_args,
  c_args: supported_c_args,
  link_args: linker_flags
)
