#ifndef FRAME_FILESTAB_H
#define FRAME_FILESTAB_H

#include <gtkmm.h>
#include <iostream>

using namespace std;

class Frame_FilesTab : public Gtk::Frame
{
    public:
        Frame_FilesTab();
        virtual ~Frame_FilesTab();

        Glib::RefPtr<Gtk::ListStore> refTreeModel;
    protected:
    private:
        void treeviewcolumn_filetype(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_filesize(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_fileprogress(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);
        void treeviewcolumn_filepriority(Gtk::CellRenderer* renderer, const Gtk::TreeModel::iterator& iter);

        class FilesColumnsClass : public Gtk::TreeModel::ColumnRecord
        {
            public:
                FilesColumnsClass()
                {
                    add(Name); add(Size); add(Progress); add(Priority);
                }
                Gtk::TreeModelColumn<string> Name;
                Gtk::TreeModelColumn<int> Size;
                Gtk::TreeModelColumn<int> Progress;
                Gtk::TreeModelColumn<int> Priority;
        };
        FilesColumnsClass FilesColumns;
};

#endif // FRAME_FILESTAB_H
