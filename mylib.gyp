
{
  'variables': {
    'target_arch%': 'x64'
  },

  'targets_defaults': {
      'conditions': [
        [ 'OS=="mac"', {
          'conditions': [
              ['target_arch=="ia32"', {
                'xcode_settings': {'ARCHS': ['i386']},
              }],
              ['target_arch=="x64"', {
                'xcode_settings': {'ARCHS': ['x86_64']},
              }],
          ]
          }
        ],
      ]
  },

  'defines': [
    'ARCH="<(target_arch)"',
    'PLATFORM="<(OS)"',
  ],

  'targets': [

    {
      'target_name': 'mylib',
      'product_name': 'mylib',
      'type': 'shared_library',
      'sources': [
        'src/implementation.cc',
      ],
      'include_dirs': [
         'include',
      ],
      'xcode_settings': {'ARCHS': ['x86_64']}

    },

    {
      'target_name': 'myapp',
      'type': 'executable',
      'sources': [
        './bin/myapp.cc',
      ],
      'include_dirs': [
         'include',
      ],
      'dependencies': [
        'mylib'
      ],
      'xcode_settings': {'ARCHS': ['x86_64']}
    },
  
  ],
}