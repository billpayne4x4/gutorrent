#include "Frame_FilesTab.h"
#include "../tools/tools_formatsize.h"
#include <algorithm>

Frame_FilesTab::Frame_FilesTab()
{
    this->set_shadow_type(Gtk::SHADOW_IN);
    this->set_margin_top(5);
    this->set_margin_left(5);
    this->set_margin_right(5);
    this->set_margin_bottom(5);

    Gtk::ScrolledWindow *ScrolledWindow = Gtk::manage(new Gtk::ScrolledWindow);
    ScrolledWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    this->add(*ScrolledWindow);

    Gtk::TreeView *tvFiles = Gtk::manage(new Gtk::TreeView);
    tvFiles->set_grid_lines(Gtk::TREE_VIEW_GRID_LINES_BOTH);
    ScrolledWindow->add(*tvFiles);

    refTreeModel = Gtk::ListStore::create(FilesColumns);
    tvFiles->set_model(refTreeModel);

    tvFiles->append_column("Name", FilesColumns.Name);


    Gtk::CellRendererText *cellrenderer_FileType = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvFiles_FileType = Gtk::manage(new Gtk::TreeView::Column);
    tvFiles_FileType->set_title("Type");
    //tvFiles_FileType->set_resizable(true);
    tvFiles_FileType->pack_start(*cellrenderer_FileType);
    tvFiles_FileType->set_cell_data_func(*cellrenderer_FileType, sigc::mem_fun(*this, &Frame_FilesTab::treeviewcolumn_filetype));
    tvFiles->append_column(*tvFiles_FileType);

    Gtk::CellRendererText *cellrenderer_FileSize = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvFiles_FileSize = Gtk::manage(new Gtk::TreeView::Column);
    tvFiles_FileSize->set_title("Type");
    //tvFiles_FileSize->set_resizable(true);
    tvFiles_FileSize->pack_start(*cellrenderer_FileSize);
    tvFiles_FileSize->set_cell_data_func(*cellrenderer_FileSize, sigc::mem_fun(*this, &Frame_FilesTab::treeviewcolumn_filesize));
    tvFiles->append_column(*tvFiles_FileSize);

    Gtk::CellRendererProgress *cellrenderer_FileProgress = Gtk::manage(new Gtk::CellRendererProgress);
    Gtk::TreeView::Column *tvFiles_FileProgress = Gtk::manage(new Gtk::TreeView::Column);
    tvFiles_FileProgress->set_title("Progress");
    //tvFiles_FileProgress->set_resizable(true);
    tvFiles_FileProgress->pack_start(*cellrenderer_FileProgress);
    tvFiles_FileProgress->set_cell_data_func(*cellrenderer_FileProgress, sigc::mem_fun(*this, &Frame_FilesTab::treeviewcolumn_fileprogress));
    tvFiles->append_column(*tvFiles_FileProgress);

    Gtk::CellRendererText *cellrenderer_FilePriority = Gtk::manage(new Gtk::CellRendererText);
    Gtk::TreeView::Column *tvFiles_FilePriority = Gtk::manage(new Gtk::TreeView::Column);
    tvFiles_FilePriority->set_title("Priority");
    //tvFiles_FilePriority->set_resizable(true);
    tvFiles_FilePriority->pack_start(*cellrenderer_FilePriority);
    tvFiles_FilePriority->set_cell_data_func(*cellrenderer_FilePriority, sigc::mem_fun(*this, &Frame_FilesTab::treeviewcolumn_filepriority));
    tvFiles->append_column(*tvFiles_FilePriority);


    // TODO: REMOVE TEST DATA BELOW
    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[FilesColumns.Name] = "File Name.Mp4";
    row[FilesColumns.Size] = (1024 * 1024) *1023 + 5504;
    row[FilesColumns.Progress] = 75;
    row[FilesColumns.Priority] = 2;
}

Frame_FilesTab::~Frame_FilesTab()
{
    //dtor
}

void Frame_FilesTab::treeviewcolumn_filetype(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        string model_value = row[FilesColumns.Name];

        string FileType = model_value.substr(model_value.find_last_of(".") + 1);
        if(model_value.compare(FileType) == 0) FileType = "[None]";

        std::transform(FileType.begin(), FileType.end(), FileType.begin(), ::tolower);

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = FileType;
    }
}
void Frame_FilesTab::treeviewcolumn_filesize(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        tools_formatsize fs;
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[FilesColumns.Size];

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = fs.format(model_value);
    }
}

void Frame_FilesTab::treeviewcolumn_fileprogress(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[FilesColumns.Progress];

        Gtk::CellRendererProgress *crp = dynamic_cast<Gtk::CellRendererProgress*>(renderer);
        crp->set_property("value", model_value);
    }
}

void Frame_FilesTab::treeviewcolumn_filepriority(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter)
{
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        int model_value = row[FilesColumns.Priority];

        string Priority = "[unknown]";
        switch(model_value)
        {
            case 0:
                Priority = "Don't Download";
                break;
            case 1:
                Priority = "Low Priority";
                break;
            case 2:
                Priority = "Normal Priority";
                break;
            case 3:
                Priority = "High Priority";
                break;
        }

        Gtk::CellRendererText *crt = dynamic_cast<Gtk::CellRendererText*>(renderer);
        crt->property_text() = Priority;
    }
}
