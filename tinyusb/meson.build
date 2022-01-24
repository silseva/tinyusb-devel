project('tinyusb', 'c')


#stupid hack
add_project_arguments('-I../platform/mcu/CMSIS/Device/ST/STM32F4xx/Include', language : 'c')
add_project_arguments('-I../platform/mcu/CMSIS/Include', language : 'c')
add_project_arguments('-I../platform/targets/MD-3x0/', language : 'c')
#add_project_arguments('-v', language : 'c')
add_project_arguments('-w', language : 'c')

tinyusb_def = {'STM32F405xx': '', 'HSE_VALUE':'8000000'}

tinyusb_args = []
foreach k, v : tinyusb_def
  if v == ''
    add_project_arguments('-D@0@'.format(k), language : 'c')
  else
    add_project_arguments('-D@0@=@1@'.format(k, v), language : 'c')
  endif
endforeach

tinyusb_inc = include_directories('src', 'hw', 'openrtx')
tinyusb_src = ['src/tusb.c',
               'src/class/audio/audio_device.c',
               'src/class/dfu/dfu_device.c',
               'src/class/dfu/dfu_rt_device.c',
               'src/class/cdc/cdc_device.c',
               'src/common/tusb_fifo.c',
               'src/portable/st/stm32_fsdev/dcd_stm32_fsdev.c',
               'src/portable/st/synopsys/dcd_synopsys.c',
               'src/device/usbd.c',
               'src/device/usbd_control.c'
               ]

tinyusb = static_library('tinyusb',
                         tinyusb_src,
                         include_directories : tinyusb_inc,
                         install : false)

tinyusb_dep = declare_dependency(include_directories : tinyusb_inc,
                                 link_with : tinyusb)



