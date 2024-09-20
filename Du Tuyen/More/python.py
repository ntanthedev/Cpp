#@title Input
from ipywidgets import widgets

dest_text = widgets.Text(description="Your drive", placeholder='Nhập đường link folder Google Drive của bạn')
source_text = widgets.Text(description="Shared drive", placeholder='Nhập đường link folder Google Drive shared')
from_page_text = widgets.Text(description="Từ trang", value="0")
to_page_text = widgets.Text(description="Đến trang", value="0")
max_download_size_text = widgets.Text(description="Tổng dung lượng tối đa(GB)", value="700")
exclude_str_text = widgets.Text(description="Bỏ file, folder có chứa nội dung", value="")

display(dest_text)
display(source_text)
display(from_page_text)
display(to_page_text)
display(max_download_size_text)
display(exclude_str_text)