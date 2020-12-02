import os

opts = Variables([], ARGUMENTS)
env = Environment(ENV = os.environ)

opts.Add(EnumVariable('target', "Compilation target", 'debug', ['d', 'debug', 'r', 'release']))

opts.Update(env)

env.Append(CCFLAGS=['-Wall', '-Wpedantic', '-Wno-sign-compare', '-static', '-I.'])
if env['target'] in ('debug', 'd'):
	env.Append(CCFLAGS=['-fPIC', '-g3', '-Og'])
	env.Append(CXXFLAGS=['-std=c++17'])
	env.Append(CPPDEFINES=['ECS_DEBUG', 'ECS_SHOW_FPS'])
else:
	env.Append(CCFLAGS=['-fPIC', '-g0', '-O3'])
	env.Append(CXXFLAGS=['-std=c++17'])

env.Append(CCFLAGS=['-lSDL2', '-lSDL2_image'])
env.Append(LINKFLAGS=['-lSDL2', '-lSDL2_image'])

env.Program("engine", [Glob('*.cpp'), Glob('Components/*.cpp'), Glob('Core/*.cpp'), Glob('Entities/*.cpp'), Glob('Systems/*.cpp')])
