code_lib = library('code-lib', files('project.cc', 'messages.cc'),
    cpp_args : '-DBUILDING_PROJECT',
    include_directories: include_directories('.'))

code_dep = declare_dependency(
    version: meson.project_version(),
    link_with: code_lib,
    include_directories: include_directories('.'))
