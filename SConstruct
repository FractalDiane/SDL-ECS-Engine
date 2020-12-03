import os

opts = Variables([], ARGUMENTS)
env = Environment(ENV = os.environ)

opts.Add(EnumVariable('target', "Compilation target", 'debug', ['d', 'debug', 'r', 'release']))
opts.Add(EnumVariable('platform', "Host/Target platform", 'linux', ['linux', 'windows']))

opts.Update(env)

if env['platform'] == 'windows':
	env = env.Clone(tools=['mingw'])
	env.Append(LINKFLAGS=['--static', '-Wl,--no-undefined', '-static-libgcc', '-static-libstdc++'])
	env.Append(CCFLAGS=['-Iinclude/SDL2-2.0.12/x86_64-w64-mingw32/include'])
	env.Append(LINKFLAGS=['-Linclude/SDL2-2.0.12/x86_64-w64-mingw32/lib', '-lSDL2main', '-lSDL2_image', '-lSDL2'])
else:
	env.Append(CCFLAGS=['-lSDL2', '-lSDL2_image'])
	env.Append(LINKFLAGS=['-lSDL2', '-lSDL2_image'])

env.Append(CCFLAGS=['-Wall', '-Wpedantic', '-Wno-sign-compare', '-static', '-I.'])
if env['target'] in ('debug', 'd'):
	env.Append(CCFLAGS=['-fPIC', '-g3', '-Og', '-ggdb'])
	env.Append(CXXFLAGS=['-std=c++17'])
	env.Append(CPPDEFINES=['ECS_DEBUG', 'ECS_SHOW_FPS'])
else:
	env.Append(CCFLAGS=['-fPIC', '-g0', '-O3'])
	env.Append(CXXFLAGS=['-std=c++17'])

env.Program("engine", [Glob('*.cpp'), Glob('Components/*.cpp'), Glob('Core/*.cpp'), Glob('Entities/*.cpp'), Glob('Systems/*.cpp')])
