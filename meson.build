project('SDL Test', 'cpp')
deps = [dependency('SDL2'), dependency('SDL2_image')]
src = [
	'Core/Input.cpp',
	'Core/Vector2.cpp',
	'Core/Window.cpp',
	'Core/World.cpp',

	'Components/Component.cpp',
	'Components/Sprite.cpp',
	'Components/Transform.cpp',

	'Entities/Entity.cpp',

	'Systems/BulletSystem.cpp',
	'Systems/PlayerSystem.cpp',
	'Systems/RenderSystem.cpp',
	
	'main.cpp'
]

if get_option('buildtype').startswith('debug')
	add_global_arguments('-DECS_DEBUG', '-DECS_SHOW_FPS', '-Og', '-g3', '-Wpedantic', language : 'cpp')
else
	add_global_arguments('-O3', '-g0', language : 'cpp')
endif

incs = include_directories('Core', 'Components', 'Entities', 'Systems')
executable('SDLTest', src, include_directories: incs, dependencies: deps)
