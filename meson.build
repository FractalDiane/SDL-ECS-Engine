project('SDL Test', 'cpp')
deps = [dependency('SDL2'), dependency('SDL2_image')]
src = [
	'Components/Behavior.cpp',
	'Components/Component.cpp',
	'Components/CustomBehavior.cpp',
	'Components/SpriteRenderer.cpp',
	'Components/Transform.cpp',
	'Entities/Entity.cpp',
	'Entities/TestEntity.cpp',
	'System/Input.cpp',
	#'System/System.cpp',
	'System/World.cpp',
	'main.cpp'
]

incs = include_directories('Components', 'Entities', 'System')
executable('SDLTest', src, include_directories: incs, dependencies: deps)
